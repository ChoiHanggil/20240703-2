#include <iostream>
#include<queue>
#include<stack>
struct Node
{
	int mData;

	Node* mpLeft;
	Node* mpRight;
	Node(int data, Node* pLeft = nullptr, Node* pRight = nullptr)
	{
		mData = data;
		mpLeft = pLeft;
		mpRight = pRight;
	}
};

class BinaryTree
{
private:
	Node* mpRoot;

public:
	BinaryTree() { mpRoot = CreateNode(0); }

	Node* GetRoot() { return mpRoot; }

	Node* CreateNode(int data)
	{
		return new Node(data);
	}

	Node* InsertLeft(Node* parent, int data)
	{
		parent->mpLeft = CreateNode(data);
		return parent->mpLeft;
	}

	Node* InsertRight(Node* parent, int data)
	{
		parent->mpRight = CreateNode(data);
		return parent->mpRight;
	}

	//BFS
	void Visit(Node* pNode) { std::cout << pNode->mData << "  "; }

	void BreadthFirst()
	{
		std::queue<Node*> q;
		q.push(mpRoot);

		while (!q.empty())
		{
			auto node = q.front();
			Visit(node);
			q.pop();

			if (node->mpLeft) { q.push(node->mpLeft); }
			if (node->mpRight) { q.push(node->mpRight); }
		}
	}

	void DepthFirst()
	{
		std::stack<Node*> s;
		s.push(mpRoot);

		while (!s.empty())
		{
			auto node = s.top();
			Visit(node);
			s.pop();

			if (node->mpRight) 
			{
				s.push(node->mpRight);
			}
			if (node->mpLeft) 
			{ 
				s.push(node->mpLeft); 
			}
		}
		
	}

	//stack -> call stack
	void DepthFirstR(Node* pNode)
	{
		//base case
		if (pNode == nullptr)
		{
			return;
		}
		//recursive vase

		//Pe-Order
		Visit(pNode);
		DepthFirstR(pNode->mpLeft);
		DepthFirstR(pNode->mpRight);
		/*
		//In-Order
		DepthFirstR(pNode->mpLeft);
		Visit(pNode);
		DepthFirstR(pNode->mpRight);

		//Post-Order
		DepthFirstR(pNode->mpLeft);
		DepthFirstR(pNode->mpRight);
		Visit(pNode);
		*/
	}
};



int main()
{
	BinaryTree myTree;
	auto pRoot = myTree.GetRoot();
	pRoot->mData = 1;

	myTree.InsertLeft(pRoot, 2);
	myTree.InsertRight(pRoot, 3);

	auto pNode = myTree.GetRoot()->mpLeft;
	myTree.InsertLeft(pNode, 4);
	myTree.InsertRight(pNode, 5);

	pNode = myTree.GetRoot()->mpRight;
	myTree.InsertLeft(pNode, 6);
	myTree.InsertRight(pNode, 7);

	myTree.BreadthFirst();
	std::cout << std::endl;
	myTree.DepthFirst();
	std::cout << std::endl;
	myTree.DepthFirstR(myTree.GetRoot());
}

//그래프 (Graph)
//	노드와 노드가 연결되는 구조

	//트리
	//트리의 꼭대기를 Root
	//트리의 가지들을 Node
	//위에있는 것을 Parent Node, 아래있는 것을 Child Node, 같은 부모을 가지는 옆에 Siblings

	//특징
	// - 오직 하나의 Root를 가짐
	// - 두 노드를 연결하는 경로는 오직 하나 
		
		//Binary Tree
		// - 각 노드가 최대 두개의 자식
	
			//Full Binary Tree
			//	모든 노드가 2개의 자식
			//Perfect Binary Tree
			//	모든 노드가 2개의 자식을 가지고 있으며 모든 리프(leaf) 노드가 같은 레벨에 있는 트리 
			// 
			//Complete Binary Tree
			//	마지막 레벨을 제외하고 모든 레벨이 완전 채워져 있으며,
			//	마지막 레벨의 모든 노드는 가장 왼쪽부터 채워져 있는 트리
			//	(Binary Search Tree)

//Graph, Thee의 순회
//	Breadth First Search(BFS)	너비 우선 탐색
//		- 가로로 읽으면 됩니다. 같운 레벨 우선으로 탐색
//		- Queue
// 
//	Depth First Search(DFS)		깊이 우선 탐색
//		- 세로로 읽으면 됩니다. 한 노드의 자식을 끝까지 탐색
//		- Stack

//Quad Tree, Oc Tree
