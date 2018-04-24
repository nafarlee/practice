(ns cbt.8-3)

(defmacro defattrs
  ([fn-name attribute]
   `(def ~fn-name (comp ~attribute :attributes)))
  ([fn-name attribute & more]
   `(do
      (defattrs ~fn-name ~attribute)
      (defattrs ~@more))))
