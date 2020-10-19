class circularQueue {
  #list;
  #vol;
  #head = -1;
  #tail = -1;
  #size = 0;

  constructor(vol) {
    this.#vol = Math.max(Number(vol), 0) || 10;
    this.#list = Array(this.#vol).fill(null);
  }
  get size() {
    return this.#size;
  }
  get isFull() {
    return this.size === this.#vol;
  }
  get isEmpty() {
    return this.size === 0;
  }

  enqueue(element) {
    if (!this.isFull) {
      this.#tail = (this.#tail + 1) % this.#vol;
      this.#list[this.#tail] = element;
      this.#size += 1;
      if (this.#head === -1) {
        this.#head = this.#tail;
      }
    }
    return this.size;
  }

  dequeue() {
    let element = null;
    if (!this.isEmpty) {
      element = this.#list[this.#head];
      this.#list[this.#head] = null;
      this.#head = (this.#head + 1) % this.#vol;
      this.#size -= 1;
      if (!this.size) {
        this.#head = -1;
        this.#tail = -1;
      }
    }
    return element;
  }

  view() {
    return this.#list[this.#head];
  }

  print() {
    console.log(this.#list);
  }
}

//const cirQ= new circular queue(10);
//cirQ.enqueue(1)
//cirQ.dequeue(1)
//console.log(cirQ.view()) 
//cirQ.print(); 


