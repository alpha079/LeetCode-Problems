class Solution {
public:
   int widthOfBinaryTree(TreeNode* root) {
	int maxWidth = 0;
	queue<pair<TreeNode*, int>> q;

	q.push({root, 0});
	while (!q.empty()) {
		int qSize = q.size();
		int levelFirstNodeIndex = q.front().second;  // to make the index start from 0
		int start, end;

		for (int i=0;i<qSize;i++) {
			TreeNode* currNode = q.front().first;
			unsigned int index = q.front().second - levelFirstNodeIndex;
			q.pop();

			if (i == 0)
				start = index;
			if (i == qSize - 1)
				end = index;

			maxWidth = max(maxWidth, end-start+1);

			if (currNode->left)
				q.push({currNode->left, 2*index});
			if (currNode->right)
				q.push({currNode->right, 2*index+1});
		}
	}

	return maxWidth;
}
};