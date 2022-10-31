// Online C++ compiler to run C++ program online
#include <iostream>

int W = 1;

class QuadTree;
    
class Point
{
private:
    int x;
    int y;
    friend class Node;
    friend class QuadTree;
public:
    Point()
    {
        this->x = this-> y = 0;
    }
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};

class Node
{
private:
    Point point;
    Node * north_east;
    Node * north_west;
    Node * south_west;
    Node * south_east;
    friend class QuadTree;
public:
    Node(int x, int y)
    {
        this->point = Point(x,y);
        this->north_east = nullptr;
        this->north_west = nullptr;
        this->south_west = nullptr;
        this->south_east = nullptr;
    }
    Node()
    {
        this->point = Point(0,0);
        this->north_east = nullptr;
        this->north_west = nullptr;
        this->south_west = nullptr;
        this->south_east = nullptr;
    }
};
class QuadTree
{
private:
    Node * root;
public:
    QuadTree()
    {
        this->root = nullptr;
    }
    void insert(int x, int y)
    {
        if (!this->root)
        {
            this->root = new Node(x,y);
            return;
        }
        Node * tmp = this->root;
        Node * tmp2 = tmp;
        while(tmp)
        {
            tmp2 = tmp;
            if (tmp->point.x > x && tmp->point.y > y)
            {
                tmp = tmp->south_west;
            }
            
            else if (tmp->point.x <= x && tmp->point.y <= y)
            {
                tmp = tmp->north_east;
            }
            
            else if (tmp->point.x < x && tmp->point.y > y)
            {
                tmp = tmp->south_east;
            }
             
            else if (tmp->point.x > x && tmp->point.y < y)
            {
                tmp = tmp->north_west;
            }
        }
        
        if (tmp2->point.x > x && tmp2->point.y > y)
        {
            tmp2->south_west = new Node(x,y);
        }
        
        else if (tmp2->point.x < x && tmp2->point.y < y)
        {
            tmp2->north_east = new Node(x,y);
        }
        
        else if (tmp2->point.x < x && tmp2->point.y > y)
        {
            tmp2->south_east = new Node(x,y);
            W++;
        }
         
        else if (tmp2->point.x > x && tmp2->point.y < y)
        {
            tmp2->north_west = new Node(x,y);
            W++;
            
        }
    }
    
    void DestroyRecursive(Node * node)
    {
        if (node)
        {
            DestroyRecursive(node->north_east);
            DestroyRecursive(node->north_west);
            DestroyRecursive(node->south_west);
            DestroyRecursive(node->south_east);
            delete node;
        }
    }

    ~QuadTree()
    {
        DestroyRecursive(this->root);
    }
    
    
    void print_pre_order(Node * node)
    {
        if (!node) return;
        std::cout << node->point.x << ' ' << node->point.y << '\n';
        print_pre_order(node->north_east);
        print_pre_order(node->north_west);
        print_pre_order(node->south_west);
        print_pre_order(node->south_east);
    }
    void print_pre_order()
    {
        print_pre_order(this->root);
    }
};

int main() {
    int T;  std::cin >> T;

    for (int i = 0; i < T; i++)
    {
        QuadTree my_tree;
        int n; std::cin >> n;
        for (int j = 0; j < n; j++)
        {
            int w,h; std::cin >> w >> h;
            my_tree.insert(w,h);
        }
        std::cout << W << '\n';
        W = 1;
    }
    return 0;
}