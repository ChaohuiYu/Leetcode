class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> ans = new ArrayList<>();
        if (root == null) return ans;
        Deque<TreeNode> q = new ArrayDeque<>();
        q.addFirst(root);
        while (!q.isEmpty()) {
            List<Integer> tmp = new ArrayList<>();
            int cnt = q.size();
            for (int i = 0; i < cnt; i++) {
                TreeNode cur = q.removeLast();
                tmp.add(cur.val);
                if (cur.left != null)
                    q.addFirst(cur.left);
                if (cur.right != null)
                    q.addFirst(cur.right);
            }
            ans.add(tmp);
        }
        return ans;
    }
}

