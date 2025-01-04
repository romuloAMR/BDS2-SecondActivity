use crate::models::color::Color;

pub enum RBTree<T : Ord> {
    NULL,
    NODE {
        value: T,
        color: Color,
        left: Option<Box<RBTree<T>>>,
        right: Option<Box<RBTree<T>>>,
        parent: Option<Box<RBTree<T>>>
    }
}

impl<T: Ord> RBTree<T> {
    pub fn new() -> Self {
        RBTree::NULL
    }

    pub fn is_red(&self) -> bool {
        match self {
            RBTree::NODE { color, .. } => *color == Color::RED,
            _ => false,
        }
    }

    pub fn is_null(&self) -> bool {
        match self {
            RBTree::NULL => true,
            _ => false,
        }
    }
}