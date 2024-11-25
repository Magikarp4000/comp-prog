
public class grader {
	public static void main(String[] args) {
		InputReader inputReader = new InputReader(System.in);
		int n = inputReader.readInt();
		int m = inputReader.readInt();
		int[] x = new int[n];
		int[] h = new int[n];
		for (int i = 0; i < n; i++) {
			x[i] = inputReader.readInt();
			h[i] = inputReader.readInt();
		}
		int[] l = new int[m];
		int[] r = new int[m];
		int[] y = new int[m];
		for (int i = 0; i < m; i++) {
			l[i] = inputReader.readInt();
			r[i] = inputReader.readInt();
			y[i] = inputReader.readInt();
		}
		int s = inputReader.readInt();
		int g = inputReader.readInt();
		inputReader.close();

		walk solver = new walk();
		long result = solver.min_distance(x, h, l, r, y, s, g);

		System.out.println(result);
		System.out.close();
	}
}

class InputReader implements java.io.Closeable {
	private java.io.InputStream stream;
	private byte[] buf = new byte[1024];
	private int curChar;
	private int numChars;

	public InputReader(java.io.InputStream stream) {
		this.stream = stream;
	}

	@Override
	public void close() {
		try {
			this.stream.close();
		} catch (java.io.IOException e) {
		}
	}

	public int read() {
		if (numChars == -1) {
			throw new java.util.InputMismatchException();
		}
		if (curChar >= numChars) {
			curChar = 0;
			try {
				numChars = stream.read(buf);
			} catch (java.io.IOException e) {
				throw new java.util.InputMismatchException();
			}
			if (numChars <= 0) {
				return -1;
			}
		}
		return buf[curChar++];
	}

	public int readInt() {
		int c = eatWhite();
		int sgn = 1;
		if (c == '-') {
			sgn = -1;
			c = read();
		}
		int res = 0;
		do {
			if (c < '0' || c > '9') {
				throw new java.util.InputMismatchException();
			}
			res *= 10;
			res += c - '0';
			c = read();
		} while (!isSpaceChar(c));
		return res * sgn;
	}

	public String readString() {
		int c = eatWhite();
		StringBuilder res = new StringBuilder();
		do {
			if (Character.isValidCodePoint(c))
				res.appendCodePoint(c);
			c = read();
		} while (!isSpaceChar(c));
		return res.toString();
	}

	public String readLine() {
		StringBuilder res = new StringBuilder();
		while (true) {
			int c = read();
			if (c == '\n' || c == '\r' || c == -1)
				break;
			if (Character.isValidCodePoint(c))
				res.appendCodePoint(c);
		}
		return res.toString();
	}

	private int eatWhite() {
		int c = read();
		while (isSpaceChar(c)) {
			c = read();
		}
		return c;
	}

	public static boolean isSpaceChar(int c) {
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}
}
