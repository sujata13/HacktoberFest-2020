def editDistance(s, t):
    """
    Calculates the minimum edit distance between two strings s and t, where an
    edit can be one of:

    - Add a character
    - Remove a character
    - Replace a character
    """
    n = len(s)
    m = len(t)

    # dp[i][j] represents the edit distance from s[:i] to t[:j]
    dp = [[0] * (m + 1) for _ in range(n + 1)]

    # The distance between any string and the empty string is its length.
    # (remove every character)
    for i in range(n + 1):
        dp[i][0] = i
    for j in range(m + 1):
        dp[0][j] = j

    for i in range(n):
        for j in range(m):
            # If the characters are the same we don't have to make an edit.
            dp[i + 1][j + 1] = dp[i][j] if s[i] == t[j] else min(
                dp[i][j + 1],  # remove s[i]
                dp[i + 1][j],  # add t[j]
                dp[i][j]  # replace s[i] with t[j]
            ) + 1
    return dp[-1][-1]
