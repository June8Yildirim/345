class ShapeFactory {
public:
  // Static method to create objects
  // Change is required only in this function to create a new object type
  static Shape* Create(string type) {
    if (type == "circle") return new Circle();
    if (type == "square") return new Square();
    return NULL;
  }
private:
  ShapeFactory() {};
};
