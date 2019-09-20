int strcmp(char *s1, char *s2)
{
    int i = 0;
    int r;
    if ((*s1 == '+' || *s1 == '-') && (*s2 == '+' || *s2 == '-'))
    {
        int num1 = *s1 == '+' ? atoi(s1 + 1) : -1 * atoi(s1 + 1);
        int num2 = *s2 == '+' ? atoi(s2 + 1) : -1 * atoi(s2 + 1);
        if (num1 > num2)
            return 1;
        else if (num1 == num2)
            return 0;
        else
            return -1;
    }
    else
    {
        while (1)
        {

            if (*(s1 + i) != *(s2 + i))
            {
                r = (int)*(s1 + i) - (int)*(s2 + i);
                if (r > 0)
                    return 1;
                else if (r == 0)
                    return 0;
                else
                    return -1;
            }
            i++;
        }
    }
}