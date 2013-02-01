// problem: Toll Road
// author : Benjamin Bieber
// date   : 2008.11.19
// method : divide-and-conquer
// runtime: O(n)

import java.io.*;
import java.util.*;

public class tollroad {

	static StreamTokenizer st = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
	static int read() throws IOException {
		st.nextToken();
		return (int)st.nval;
	}

	// edges of the graph
	static class Road {
		int fromTown;
		int toTown;
		int fee;

		Road(int from, int to, int p) {
			fromTown = from;
			toTown = to;
			fee = p;
		}
	}

	// each node has a list of adjacent edges
	static Map<Integer, ArrayList<Road>> roadMap;

	// insert a new edge into the graph
	static void addRoad(int from, int to, int p) {
		if (!roadMap.containsKey(from)) {
			roadMap.put(from, new ArrayList<Road>());
		}
		roadMap.get(from).add(new Road(from, to, p));
	}

	// global maximum
	static int maxFound = 0;

	// maximum sum of a subtree whose root has edges t and predecessor parent
	static int dfs(ArrayList<Road> t, int parent) {
		int sum = 0;
		for (int i = 0; i < t.size(); ++i) {
			Road road = t.get(i);
			// do not return to parent
			if (road.toTown != parent) {
				int sumSubtree = dfs(roadMap.get(road.toTown), road.fromTown) + road.fee;
				if (sumSubtree > 0) {
					// take only positive subtrees
					sum += sumSubtree;
				}
			}
		}
		// keep the maximum over all subtrees
		if (sum > maxFound) {
			maxFound = sum;
		}
		return sum;
	}

	public static void main(String[] args) throws IOException {
		while (true) {
			int numRoads = read();
			if (numRoads == 0) break;

			roadMap = new HashMap<Integer, ArrayList<Road>>();
			maxFound = 0;

			// build adjacency lists of graph
			int a = -1;
			while (numRoads > 0) {
				a = read();
				int b = read();
				int p = read();
				addRoad(a, b, p);
				addRoad(b, a, p);
				numRoads--;
			}

			// start at arbitrary node
			ArrayList<Road> start = roadMap.get(a);
			dfs(start, -1);
			System.out.println(maxFound);
		}
	}

}
