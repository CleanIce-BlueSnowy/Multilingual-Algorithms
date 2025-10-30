#![allow(non_snake_case)]

pub struct UnionFind {
    father: Box<[usize]>,
}

impl UnionFind {
    pub fn new(length: usize) -> Self {
        let mut this = Self {
            father: vec![0; length].into_boxed_slice(),
        };
        for i in 0..length {
            this.father[i] = i;
        }
        return this;
    }

    pub fn merge(&mut self, x: usize, y: usize) {
        if !self.is_connected(x, y) {
            self.father[self.find_root(x)] = self.find_root(y);
        }
    }

    pub fn is_connected(&mut self, x: usize, y: usize) -> bool {
        self.find_root(x) == self.find_root(y)
    }

    pub fn size(&self) -> usize {
        self.father.len()
    }

    pub fn num_blocks(&mut self) -> usize {
        let mut visited = vec![false; self.father.len()].into_boxed_slice();
        let mut res = 0;
        for i in 0..self.father.len() {
            let root = self.find_root(i);
            if !visited[root] {
                res += 1;
                visited[root] = true;
            }
        }
        res
    }

    fn find_root(&mut self, x: usize) -> usize {
        if self.father[x] == x {
            x
        } else {
            let temp = self.find_root(self.father[x]);
            self.father[x] = temp;
            temp
        }
    }
}
