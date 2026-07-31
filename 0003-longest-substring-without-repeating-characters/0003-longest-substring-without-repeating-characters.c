int lengthOfLongestSubstring(char *s)
{
    int visited[128] = {0};

    int left = 0;
    int right = 0;
    int maxLen = 0;

    while (s[right] != '\0')
    {
        while (visited[s[right]])
        {
            visited[s[left]] = 0;
            left++;
        }

        visited[s[right]] = 1;

        int currentLen = right - left + 1;

        if (currentLen > maxLen)
            maxLen = currentLen;

        right++;
    }

    return maxLen;
}