import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**8)

class Node :
    def __init__(self, B, A=None) :
        self.item = B
        self.anscestor = A
    
def get_anscestors(node_dict : dict, child : int, anscestor : list) :
    child_node = node_dict[child]
    if not child_node.anscestor :
        return anscestor
    anscestor_node = node_dict[child_node.anscestor]
    anscestor.append(anscestor_node.item)
    return get_anscestors(node_dict, child_node.anscestor, anscestor)
    
if __name__ == "__main__" :
    T = int(input().rstrip())
    for testcase in range(T) :
        num_node = int(input().rstrip())

        numbers = set([])
        nodes = {}

        for _ in range(num_node - 1) :
            A, B = map(int, input().rstrip().split(' '))
            if A not in numbers :
                numbers.add(A)
                nodes[A] = Node(A, None)
            if B not in numbers :
                numbers.add(B)
            nodes[B] = Node(B, A)
                
        node1, node2 = map(int, input().rstrip().split(' '))
        # get anscestors
        anscestor_1 = [node1]
        anscestor_2 = [node2]
        anscestor_1 = get_anscestors(nodes, node1, anscestor_1)
        anscestor_2 = get_anscestors(nodes, node2, anscestor_2)
        print([_ for _ in anscestor_1 if _ in anscestor_2][0])