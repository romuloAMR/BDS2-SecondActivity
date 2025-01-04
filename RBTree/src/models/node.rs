use crate::models::color::Color;

#[derive(Debug)]
pub struct Node<T: Ord> {
    pub value: T,
    pub color: Color,
    pub left: Option<Box<Node<T>>>,
    pub right: Option<Box<Node<T>>>,
    pub parent: Option<*mut Node<T>>,
}

impl<T: Ord> Node<T> {
    pub fn new(value: T, color: Color) -> Self {
        Node {
            value,
            color,
            left: None,
            right: None,
            parent: None,
        }
    }

    pub fn is_red(node: Option<&Box<Node<T>>>) -> bool {
        match node {
            Some(n) => n.color == Color::RED,
            None => false,
        }
    }

    pub fn is_null(node: Option<&Box<Node<T>>>) -> bool {
        node.is_none()
    }

    pub fn get_brother(&self) -> Option<&Box<Node<T>>> {
        match self.parent {
            Some(p) => {
                let parent = unsafe { &*p };
                if self.value < parent.value {
                    parent.right.as_ref()
                } else {
                    parent.left.as_ref()
                }
            }
            None => None,
        }
    }
}