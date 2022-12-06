#include <stdio.h>
#include <assert.h>

#define Test_Code 1

int alertFailureCount = 0;

#ifdef Test_Code
int networkAlertStub(float celcius) {
    int returnValue = 0;
    printf("ALERT: Temperature is %.1f celcius.\n", celcius);
    // Return 200 for ok
    // Return 500 for not-ok
    // stub always succeeds and returns 200
    if(celcius > 500.0)
    {
        returnValue = 500;
    }
    else
    {
        returnValue = 200;
    }
    return returnValue;
}
#endif

void alertInCelcius(float farenheit) {
    int returnCode = 0;
    float celcius = (farenheit - 32) * 5 / 9;
    #ifdef Test_Code
    returnCode = networkAlertStub(celcius);
    #endif
    if (returnCode != 200) {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount = alertFailureCount+1;
        
        assert(alertFailureCount == 0);
    }
    (void)celcius;
}

int main() {
    alertInCelcius(400.5);
    alertInCelcius(303.6);
    alertInCelcius(1000);
    printf("%d alerts failed.\n", alertFailureCount);
    printf("All is well (maybe!)\n");
    
    return 0;
}
