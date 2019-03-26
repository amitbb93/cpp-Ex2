namespace ariel
{

struct node
{
	public:
	int data;
	struct node* left;
	struct node* right;
	struct node* parent;
	int size;
	node();
	node(int key);
};
	
	class Tree
	{
		public:
		node* r;	
		Tree();
		void insert(int key);
		bool contains(int key);
		int root();
		int parent(int key);
		int left(int key);
		int right(int key);
		void print();
		void remove(int key);
		int size();
		
		void insert1(int key, node *r);
		node* search(int key, node *leaf);
		int parent1(int key, node *leaf, node* p);
		void print1(node * leaf);
		node* deleteNode(node* root, int key);
		void deleteTree(node* n);
		node* getNode();
		node* FindMin(node *root);
	};	
}