(ns cbt.core
  (:require [cbt.3-1])
  (:require [cbt.3-2])
  (:require [cbt.3-3])
  (:require [cbt.3-4])
  (:require [cbt.3-5])
  (:require [cbt.3-6])
  (:gen-class))

(defn -main
  [& args]
  (println (cbt.3-6/best-symmetrize-body-parts 100)))
