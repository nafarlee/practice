(ns cbt.5-2)

(defn comp'
  [& fns]
  #(reduce (fn [val new-fn]
             (new-fn val))
           %
           (reverse fns)))
