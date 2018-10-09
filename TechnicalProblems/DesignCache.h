#pragma once
#ifndef _DESIGN_CACHE_H_
#define _DESIGN_CACHE_H_

/**
 * Problem: Design a distributed key-value caching system.
 *
 * Steps for caching:
 *	1. Check if entry is in cache.
 *	2. If the entry is in cache, read it back from the cache to the app.
 *	3. If the entry is not in cache, get the entry from the database, save the 
 *		entry back to the cache, and then read it.
 */
class DesignCache
{
	/* For system design questions, one of the first things that should be done
	 * is to come up with features that the system should support. Here are some
	 * questions that should be asked:
	 *	1. What is the amount of data that needs to be cached? Assume that the
	 *		total size of the cache is 30 TBs.
	 *	2. What is the eviction strategy of the cache (i.e. if the cache is full,
	 *		what strategy should be used to free up memory for recent entries)?
	 *	3. What should the access pattern be for the cache?
	 *		Note: There are three main types of caching systems.
	 *			Write-through Cache: Data is written to both the cache and the
	 *				database. This approach is useful if the app needs to write
	 *				data to the database and re-read that information back quickly
	 *				However, writes will be slower, since data must be written to
	 *				both the cache and the database.
	 *			Write-around Cache: Data is written to the database directly. In
	 *				the event that the cache doesn't have the data that was just 
	 *				written, it will retrieve the data from the database. This
	 *				approach has a faster writing time than a write-through cache,
	 *				but the reading latency for that data will be higher, since
	 *				the cache must retrieve that data from the database.
	 *			Write-back Cache: Data is written to the cache, and the cache will
	 *				asynchronously write this data to the database. This approach
	 *				leads to a lower write and read latency, since the data will
	 *				be stored in the cache. However, if the caching layer somehow
	 *				removes that data before the data is written to the database,
	 *				then data loss will occur. */

	/* After the features of the system have been discussed, we can start to 
	 * estimate how scalable the system needs to be. Here are some questions that
	 * should be asked in estimating the scalability of this system:
	 *	1. How many queries per second do we expect for this system?
	 *		This question is important, since a really high QPS could easily lead
	 *		to high reading/writing latency to the cache and the database, or to
	 *		the machine not being able to handle that many queries at once.
	 *	2. What is the number of machines that are required to cache this data?
	 *		Typically, a cache needs to be fast in writes/reads. Thus, caches need
	 *		to go into RAM. A production-level cache machine would typically have 
	 *		72 GB or 144 GB of RAM. Assuming that we are using 72 GB machines, we
	 *		would need at minimum (3 TB / 72 GB) machines to hold the contents 
	 *		of the cache. */

	/* Then, we can start to talk about the design goals of this application.
	 * The design goals should cover the following concepts:
	 *	1. Latency: Is the problem latency-sensitive? Are requests that have a
	 *		high latency, or requests that fail, really bad?
	 *	2. Consistency: Does the problem require tight consistency in performance?
	 *		Or is it alright if the performance of the application varies?
	 *	3. Availability: Does the problem need to be available for use 100% of 
	 *		time?
	 *
	 * Assume that the problem is latency-sensitive, since the point of using a
	 * cache in the first place is to lower the latency. There is a tradeoff
	 * between consistency and availability for the cache. If the cache is
	 * prioritizing for consistency, then it could go offline occasionally for
	 * some requests to ensure that the latency remains the same for other requests.
	 * If the cache is prioritizing for availability, then it will always remain
	 * online for all requests, but the latency betwen each request may vary. */

	/* We can now dive deeper into the individual components of the problem.
	 * Here are some questions that involve such components:
	 *	1. How would a LRU cache work on a single machine which is single-threaded?
	 *		Because the machine is single-threaded, we could just use a hash map
	 *		and a linked list, where the hash map maps keys to their corresponding
	 *		linked list node, and the linked list sorts nodes by their time of
	 *		usage. The hash map will move the most recently used key-value nodes
	 *		to the front of the linked list. Note that the linked list is only
	 *		needed to determine which key-value pair to evict from the cache when
	 *		it hits capacity. 
	 *	2. How would a LRU cache work on a single machine which is multi-threaded?
	 *		Like with most concurrent systems, write operations on the shared
	 *		resource will conflict with read and other write operations. Instead
	 *		of having a lock on the entire hash map, which would increase latency
	 *		for read and write operations even if they weren't affecting the same
	 *		index in the hash map, we could have a lock on each index of the hash
	 *		map. If a read operation hashes its key to index X, and a write
	 *		operation hashes its key to index Y, then the operations shouldn't
	 *		conflict with each other. 
	 *	3. Now that a single server's components have been fleshed out, how do
	 *		we shard?
	 *		Note that sharding is a method of splitting and storing a single
	 *		dataset into multiple databases. */
};

#endif	// _DESIGN_CACHE_H_