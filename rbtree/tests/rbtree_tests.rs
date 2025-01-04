use rbtree::models::rbtree::RBTree;
use rbtree::models::color::Color;

#[test]
fn test_new_and_null_tree() {
    let tree: RBTree<i32> = RBTree::new();
    assert!(tree.is_null());
}

#[test]
fn test_is_red() {
    let red_node = RBTree::NODE {
        value: 10,
        color: Color::RED,
        left: None,
        right: None,
        parent: None,
    };
    assert!(red_node.is_red());

    let black_node = RBTree::NODE {
        value: 20,
        color: Color::BLACK,
        left: None,
        right: None,
        parent: None,
    };
    assert!(!black_node.is_red());

    let null_tree: RBTree<i32> = RBTree::NULL;
    assert!(!null_tree.is_red());
}