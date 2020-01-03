package com.cz.hello.spring.transaction.dao;

import com.cz.hello.spring.transaction.domain.TbContentCategory;
import org.springframework.stereotype.Repository;

/**
 * @author CHANG Zheng
 * @version 1.0.0
 * @projectName hello-spring-transaction
 * @date 2020/1/2 22:18
 */
@Repository
public interface TbContentCategoryDao
{
    void insert(TbContentCategory tbContentCategory);
}
