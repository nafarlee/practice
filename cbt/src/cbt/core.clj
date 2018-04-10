(ns cbt.core
  (:require [cbt.1-1])
  (:require [cbt.1-2])
  (:require [cbt.1-3])
  (:require [cbt.1-4])
  (:require [cbt.1-5])
  (:require [cbt.1-6])
  (:gen-class))

(defn -main
  [& args]
  (println (cbt.1-6/best-symmetrize-body-parts 100)))
