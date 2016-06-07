package net.alcetech.ApplicationFramework;

public class Wildcard {
	
	public static boolean matches(String input, String pattern) {
		
		int length = input.length();
		int patlen = pattern.length();
		int j = 0;
		boolean matches = true;

		for (int i = 0; i < length; i++)
		{
			if (j >= patlen) {
				if (i < length)
				{
					// printf("pattern reached end before string\n");
					matches = false;
				}
				break;
			}

			if (pattern.charAt(j) == '*') {
				// match everything
				if (j + 1 < patlen) {
					if (pattern.charAt(j + 1) == input.charAt(i)) {
						j++;
						i--;
						continue;
					}
				}
			}
			else if (pattern.charAt(j) == '?') {
				// match any single character
				j++;
			}
			else {
				if (pattern.charAt(j) == input.charAt(i)) {
					j++;
					continue;
				}
				else {
					// printf("pattern[%d] '%c' does not equal this->charAt(%d) '%c'\n", j, pattern[j], i, this->charAt(i));
					matches = false;
					break;
				}
			}
		}
		
		// if we haven't completely matched the pattern and we weren't set to match-all, return false
		if (j < pattern.length() - 1) return false;
		
		return matches;
	}

}
