(ns cbt.10-2)

(def url "https://www.braveclojure.com/random-quote")

(defn get-quote
  []
  (future (slurp url)))

(defn get-quotes
  [n]
  (-> n
      (repeatedly get-quote)
      doall))

(def to-words (partial re-seq #"\w+"))

(defn word-frequencies
  [s]
  (->> s
       to-words
       frequencies))

(defn quote-word-count
  [n]
  (let [counts (atom {})
        futures (get-quotes n)]
    (doseq [q futures]
      (swap! counts
             #(merge-with + % (word-frequencies @q))))
    @counts))
