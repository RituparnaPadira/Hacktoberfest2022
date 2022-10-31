def stoneGameVI(self, alice: List[int], bob: List[int]) -> int:
        arr = sorted([(-(a + b), a, b) for a, b in zip(alice, bob)])
        delta = 0

        for i in range(len(bob)):
            if not i % 2:
                delta += arr[i][1]
            else:
                delta -= arr[i][2]

        if delta > 0:
            return 1
        if delta < 0:
            return -1

        return 0
