/* This sample is used to put the MRI debug monitor through its paces before a release. */
#include <mbed.h>
#include <mri.h>

// Assembly language functions found in tests.S
extern "C" void testContextWithCrash(void);
extern "C" void testContextWithHardcodedBreakpoint(void);
extern "C" void testStackingHandlerException(void);

// Forward function declarations.
static void __attribute__ ((noinline)) breakOnMe();
static void runThreads(osPriority thread1Priority, osPriority thread2Priority);
static void thread1Func(const void* pv);
static void thread2Func(const void* pv);
static void runFileTests();


// Selection variable to be set from GDB.
static volatile int g_selection = 0;

int main(void)
{
    while (1)
    {
        printf("\n");
        printf("1) Set registers to known values and crash.\n");
        printf("2) Set registers to known values and stop at hardcoded bkpt.\n");
        printf("3) Call breakOnMe() to increment g_global\n");
        printf("4) Run 2 threads at normal priority\n");
        printf("5) Run Semi-Hosting tests\n");
        printf("6) Trigger mbed hard fault handler\n");


        printf("Set selection in g_selection:\n");
        g_selection = 0;
        __debugbreak();
        while (g_selection == 0)
        {
        }

        switch (g_selection) {
            case 1:
                testContextWithCrash();
                break;
            case 2:
                testContextWithHardcodedBreakpoint();
                break;
            case 3:
                printf("Delaying 10 seconds...\n");
                wait_ms(10000);
                breakOnMe();
                break;
            case 4:
                runThreads(osPriorityNormal, osPriorityNormal);
                break;
            case 5:
                runFileTests();
                break;
            case 6:
                testStackingHandlerException();
                break;
            default:
                printf("Invalid selection\n");
                break;
        }
    }
}

static volatile uint32_t g_global;

static void __attribute__ ((noinline)) breakOnMe()
{
    g_global++;
    __DSB();
}

static volatile bool g_stop = false;
static void runThreads(osPriority thread1Priority, osPriority thread2Priority)
{
    wait_ms(250);
    printf("Set g_stop to true to end test...\n");

    osThreadDef(thread1Func, thread1Priority, 1024);
    osThreadId thread1 = osThreadCreate(&os_thread_def_thread1Func, NULL);

    osThreadDef(thread2Func, thread2Priority, 1024);
    osThreadId thread2 = osThreadCreate(&os_thread_def_thread2Func, NULL);

    while (!g_stop)
    {
        // Wait for user input.
    }

    osThreadTerminate(thread1);
    osThreadTerminate(thread2);
}

static void thread1Func(const void* pv)
{
    while (true )
    {
        wait_ms(1000);
        printf("Thread1 Output\n");
    }
}

static void thread2Func(const void* pv)
{
    while (true )
    {
        wait_ms(2000);
        printf("Thread2 Output\n");
    }
}


LocalFileSystem local("local");             // Create the local filesystem under the name "local"

static void runFileTests()
{
    int  Result = -1;
    long Offset = -1;
    char Buffer[32];

    printf("LocalFileSystem/Semi-hosting Tests\n");

    printf("Test 1: fopen() for write\n");
    FILE *fp = fopen("/local/out.txt", "w");  // Open "out.txt" on the local file system for writing
    if (NULL == fp)
    {
        error("%s(%d) fopen() failed\n", __FILE__, __LINE__);
    }

    printf("Test 2: fprintf()\n");
    Result = fprintf(fp, "Hello World!");
    if (Result < 0)
    {
        error("%s(%d) fprintf() failed\n", __FILE__, __LINE__);
    }

    printf("Test 3: fclose() on written file\n");
    Result = fclose(fp);
    if (0 != Result)
    {
        error("%s(%d) fclose() failed\n", __FILE__, __LINE__);
    }



    printf("Test 4: fopen() for read\n");
    fp = fopen("/local/out.txt", "r");
    if (NULL == fp)
    {
        error("%s(%d) fopen() failed\n", __FILE__, __LINE__);
    }

    printf("Test 5: fscanf()\n");
    Result = fscanf(fp, "%31s", Buffer);
    if (EOF == Result)
    {
        error("%s(%d) fscanf() failed\n", __FILE__, __LINE__);
    }
    printf("Contents of /local/out.txt: %s\n", Buffer);
    if (0 != strcmp(Buffer, "Hello"))
    {
        error("%s(%d) fscanf read out wrong string\n", __FILE__, __LINE__);
    }

    printf("Test 6: Determine size of file through fseek and ftell calls\n");
    Result = fseek(fp, 0, SEEK_END);
    if (0 != Result)
    {
        error("%s(%d) fseek(..,0, SEEK_END) failed\n", __FILE__, __LINE__);
    }
    Offset = ftell(fp);
    if (12 != Offset)
    {
        error("%s(%d) ftell didn't return the expected value of 12\n", __FILE__, __LINE__);
    }

    printf("Test 7: fclose() on read file\n");
    Result = fclose(fp);
    if (0 != Result)
    {
        error("%s(%d) fclose() failed\n", __FILE__, __LINE__);
    }



    printf("Test 8: remove()\n");
    Result = remove("/local/out.txt");                 // Removes the file "out.txt" from the local file system
    if (0 != Result)
    {
        error("%s(%d) remove() failed\n", __FILE__, __LINE__);
    }

    printf("\nTest completed\n");
}
