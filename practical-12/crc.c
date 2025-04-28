#include <stdio.h>
#include <string.h>
#define GENERATOR "1011" // CRC divisor (polynomial)
// Function to perform XOR operation
void xorOperation(char dividend[], char divisor[], int len)
{
    for (int i = 0; i < len; i++)
    {
        dividend[i] = (dividend[i] == divisor[i]) ? '0' : '1';
    }
}
// Function to perform CRC division
void computeCRC(char data[], char generator[], char crc[])
{
    int dataLen = strlen(data);
    int genLen = strlen(generator);
    char temp[20];
    strcpy(temp, data); // Copy input data
    int i = 0;
    // Perform division
    while (i <= dataLen - genLen)
    {
        xorOperation(&temp[i], generator, genLen);
        while (i < dataLen && temp[i] != '1') // Move to next '1'
            i++;
    }

    // Extract the remainder as CRC
    strcpy(crc, &temp[dataLen - genLen + 1]);
}

// Function to append CRC to the original data and check validity
void checkCRC(char transmittedData[], char generator[])
{
    char remainder[20];
    computeCRC(transmittedData, generator, remainder);

    // If remainder is all 0s, no error
    if (strchr(remainder, '1') == NULL)
        printf("No error detected! Data received correctly.\n");
    else
        printf("Error detected in received data!\n");
}
int main()
{
    char data[] = "1101101"; // Input data bits
    char generator[] = GENERATOR;

    int genLen = strlen(generator);
    char transmittedData[50], crc[20];

    // Append zeros to the data
    strcpy(transmittedData, data);
    strcat(transmittedData, "000"); // Appending n-1 (3) zeros

    // Compute CRC
    computeCRC(transmittedData, generator, crc);
    printf("CRC Checksum: %s\n", crc);
    // Append CRC to the original message
    strcat(data, crc);
    printf("Transmitted Data with CRC: %s\n", data);
    // Receiver side verification
    checkCRC(data, generator);
    return 0;
}
