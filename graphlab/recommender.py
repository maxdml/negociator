#!/usr/bin/python

import graphlab as gl

train_data = gl.SFrame.read_csv('SimLargeResults.csv');

model = gl.ranking_factorization_recommender.create(train_data, 'benchmark', 'configuration', 'performance', num_factors=1)

results = model.recommend(exclude_known = False)

results.print_rows(147,4)
