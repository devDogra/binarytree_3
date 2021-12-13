#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <deque>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>

struct node
{
	int data;
	node* left;
	node* right;

	node(int d) { data = d; left = nullptr; right = nullptr;}
};

bool leaf(node* root)
{
	return (!root->left and !root->right)? true : false;
}


node* build_tree()
{
	node* root = new node(1);

	root->left = new node(2);
	root->right = new node(3);

	root->left->left = new node(4);
	root->left->right = new node(5);
	root->right->left = new node(6);
	root->right->right = new node(30);



	root->left->left->left = new node(8);
	root->left->left->right = new node(9);
	root->left->right->left = new node(10);
	root->left->right->right = new node(11);

	root->right->left->left = new node(20);



	return root;

}

node* build_tree2()
{
	node* root = new node(3);
	root->left = new node(5);
	root->left->left = new node(6);
	// root->left->left->left = new node(11);
	// root->left->left->right = new node(12);
	root->left->right = new node(2);
	root->left->right->right = new node(4);
	// root->left->right->right->right = new node(8);
	// root->left->right->right->left = new node(7);
	// root->left->right->right->left->right = new node(13);
	root->left->right->left = new node(7);
	root->right = new node(1);
	root->right->right = new node(8);
	root->right->left = new node(0);

	return root;
}

// returns the address of x in the tree 'root' if not found returns nullptr
node* find(node* root, int x)
{


    if (!root) return nullptr;

	// f_node stores the address of x if it is found in the tree at that node, 
	// and stores nullptr otherwise
    node* f_left = find(root->left, x);
    node* f_right = find(root->right, x);
    node* f_root = (root->data == x) ? root  : nullptr;



    // if (f_left != nullptr) return f_left;
	// else if (f_right != nullptr) return f_right;
	// else if (f_root != nullptr) return f_root; 
	// else return nullptr;

	return (f_left) ? f_left 
			: (f_right) ? f_right 
				: (f_root) ? f_root 
					: nullptr;
	

}

/******* NOT TESTED ******/
// returns true if x is in the tree, returns false otherwise
bool in_tree(node* root, int x)
{
	if (!root) return false;
	
	if (root->data == x) return true;
	else if (in_tree(root->left, x) or in_tree(root->right, x) ) return true; 
	else return false; 

}

void postorder(node* root)
{
    if (!root) return;

    postorder(root->left);
    postorder(root->right);
    std::cout << root->data << "    ->    " << root << std::endl;
}

void preorder_paths(node* root, std::vector<std::string>& paths, std::string currpath)
{
	if (!root) return;

	currpath += (std::to_string(root->data));

	if (leaf(root)){
		paths.push_back(currpath);
		return;
	}

	currpath+="->";

	if (root->left) preorder_paths(root->left, paths, currpath);
	if (root->right) preorder_paths(root->right, paths, currpath);

}


// sum of left leaves. pass a flag to denote whether each node is a left child or a right child???
// -1 = left child, 1 = right child, 0 means startubg root

void SLL(node* root, int flag, int& sum)
{

	if (!root) return;

	if (leaf(root)){
		if (flag == -1){
			sum += root->data;
		}
	}

	SLL(root->left, -1, sum);
	SLL(root->right, 1, sum);
}

int main()
{
	node* root= build_tree2();
	int sum = 0;
	int flag = 0;
	SLL(root, flag, sum);

	std::cout << "sll = " << sum << std::endl; 


}
