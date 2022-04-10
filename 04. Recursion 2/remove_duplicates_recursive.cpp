void removeConsecutiveDuplicates(char *input)
{
    if (*input == '\0')
        return;
    int i = 1;
    if (*input == *(input + 1))
    {
        for (; *(input + i) != '\0'; i++)
        {
            *(input + i) = *(input + i + 1);
        }
        *(input + i) = '\0';
        removeConsecutiveDuplicates(input);
    }
    removeConsecutiveDuplicates(input + 1);
}