import java.util.*;

public class SearchProblem {
    private static int N;
    private static ArrayList<Integer> initial_positions;
    private static ArrayList<Integer> goal_positions;
    private static ArrayList<ArrayList<Integer>> doublepositions;

    private static int get_N() {
        System.out.print("Input N: ");
        return new Scanner(System.in).nextInt();
    }

    private static void construct_positions() {
        initial_positions = new ArrayList<Integer>();
        goal_positions = new ArrayList<Integer>();

        for(int i = 0; i < N; i++) {
            initial_positions.add(i + 1);
            goal_positions.add(i + 1);
        }
        Collections.shuffle(initial_positions);
    }

    private static void display_arraylist(List<Integer> l) {
        System.out.print("[");
        int i;
        for(i = 0; i < N - 1; i++)
            System.out.print(l.get(i) + ", ");
        System.out.println(l.get(i) + "]");
    }

    private static void display_path(){
        ArrayList<ArrayList<Integer>> path = new ArrayList<ArrayList<Integer>>();
        path.add(0, doublepositions.get(doublepositions.size() - 1));
        int size = doublepositions.size() - 1;

        while(size != 0) {
            if(size % (N-1) == 0)
                size /= N - 1;
            else
                size = size / (N-1) + 1;

            path.add(0, doublepositions.get(size - 1));
            size -= 1;
        }

        System.out.print("Path: ");
        System.out.println(path);

        System.out.println("UCS: " + (path.size()-1));
        System.out.println("Expands: " + (doublepositions.size()-1));
    }

    public static ArrayList<Integer> transition_towards(int k) {
        int i;
        ArrayList<Integer> next_position = new ArrayList<>();

        for(i = 0; i < k; i++)
            next_position.add(initial_positions.get(i));

        Collections.reverse(next_position);

        for(int j = i; j < N; j++)
            next_position.add(initial_positions.get(j));

        return next_position;
    }

    public static void uniform_cost_search() {
        if(initial_positions.equals(goal_positions)) return;

        doublepositions = new ArrayList<ArrayList<Integer>>();
        doublepositions.add(initial_positions);
        int child = 1;
        while(true) {
            for(int k = 2; k <= N; k++) {
                initial_positions = transition_towards(k);
                doublepositions.add(initial_positions);

                if(initial_positions.equals(goal_positions))
                    return;

                initial_positions = transition_towards(k);
            }
            initial_positions = doublepositions.get(child);
            child++;
        }
    }

    public static void main(String args[]) {
        N = get_N();

        construct_positions();

        System.out.print("\nInitial: ");
        display_arraylist(initial_positions);
        System.out.print("Goal: ");
        display_arraylist(goal_positions);

        uniform_cost_search();
        display_path();
    }
}
