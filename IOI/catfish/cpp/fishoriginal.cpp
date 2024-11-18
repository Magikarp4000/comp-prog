FOR(k,0,yn+2) {
    if (j >= k) {
        dp[i][j][k] = dp1[i-1][k]+p[i-1][j]-p[i-1][k];
        dp[i][j][k] = max(dp[i][j][k], dp2[i-1][k][j]+p[i-1][j]);
        dp[i][j][k] = max(dp[i][j][k], dp3[i-1][k][j]);
    }
    else {
        dp[i][j][k] = dp3[i-1][k][0]+p[i][k]-p[i][j];
    }
    FOR(l,0,yn+2) {
        if (j >= k) {
            dp[i][j][k] = max(dp[i][j][k], dp[i-1][k][l]+max(0LL,p[i-1][j]-p[i-1][max(k,l)]));
        }
        else {
            dp[i][j][k] = max(dp[i][j][k], dp[i-1][k][l]+p[i][k]-p[i][j]);
        }
    }
}
FOR(j,0,yn+2) {
    FOR(k,0,yn+2) {
        if (k <= j) dp1[i][j] = max(dp1[i][j], dp[i][j][k]);
        else dp2[i][j][k] = max(dp2[i][j][k-1], dp[i][j][k]-p[i][k]);
    }
    FORR(k,yn+1,-1) {
        dp3[i][j][k] = max(dp3[i][j][k+1], dp[i][j][k]);
    }
}