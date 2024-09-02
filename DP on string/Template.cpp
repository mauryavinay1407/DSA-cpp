1. If you have two strings.

/* Pre-processing. Define basic cases. */
for( int i = 1; i <= m; i++){
	for( int j = 1; j <= n; j++){
		if(s1[i - 1] == s2[j - 1]){
			/* Your code */
		}
		else{
			/* Your code */
		}
	}
}

2. If you are given only one string

/* Pre-processing. Define basic cases. */
for( int len = 1; len < n; len++){
	for( int i = 0; i + len < n; i++){
		int j = i + len;
		if(s1[i - 1] == s1[j - 1]){
			/* Your code */
		}
		else{
			/* Your code */
		}
	}
}
