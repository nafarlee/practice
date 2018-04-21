(ns cbt.7-2)

(defn infix
  [expr]
  (loop [before '()
         [x op y & xs :as all] expr
         precedence 2]
    (cond
      (= precedence 0)
        (first all)
      (op-matches-precedent? precedence op)
        (recur '()
               (concat before
                       (list (list op x y))
                       xs)
               precedence)
      (nil? op)
        (recur '()
               (concat before all)
               (dec precedence))
      :else
        (recur (concat before (list x op))
               (conj xs y)
               precedence))))

(defn op-matches-precedent?
  [precedence op]
  (or 
    (and (or (= op '/)
             (= op '*))
         (= precedence 2))
    (and (or (= op '+)
             (= op '-))
         (= precedence 1))))
