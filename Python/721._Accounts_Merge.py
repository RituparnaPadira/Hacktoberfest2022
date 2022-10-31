def accountsMerge(self, accounts: List[List[str]]) -> List[List[str]]:
        N = len(accounts)

        par = [i for i in range(N)]
        size = [1] * N

        def uFind(node):
            if node == par[node]:
                return node
            par[node] = uFind(par[node])
            return par[node]

        def uUnion(a, b):
            parA = uFind(a)
            parB = uFind(b)

            if parA == parB:
                return

            if size[parA] > size[parB]:
                par[parB] = parA
                size[parA] += size[parB]
            else:
                par[parA] = parB
                size[parB] += size[parA]

        mapMailNode = {}
        for i in range(N):
            for j in range(1, len(accounts[i])):
                mail = accounts[i][j]
                if mail not in mapMailNode:
                    mapMailNode[mail] = i
                else:
                    uUnion(i, mapMailNode[mail])

        mergedMail = [[] for i in range(N)]
        #print(res)
        for k, v in mapMailNode.items():
            mail = k
            node = uFind(v)
            mergedMail[node].append(mail)

        res = []
        for i, m in enumerate(mergedMail):
            if m:
                res.append([accounts[i][0]] + sorted(m))

        return res
