package cn.itcast.store.web.servlet;

import java.io.IOException;
import java.util.List;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import cn.itcast.store.domain.Category;
import cn.itcast.store.service.CategoryService;
import cn.itcast.store.service.serviceImpl.CategoryServiceImpl;
import cn.itcast.store.web.base.BaseServlet;

/**
 * Servlet implementation class IndexServlet
 */
public class IndexServlet extends BaseServlet {
	private static final long serialVersionUID = 1L;

	@Override
	public String execute(HttpServletRequest req, HttpServletResponse resp) throws Exception
	{
		// TODO Auto-generated method stub
		// 调用业务层功能：获取全部分类信息，返回集合
		CategoryService categoryService = new CategoryServiceImpl();
		List<Category> list = categoryService.getAllCats();
		// 将返回的集合放入request
		req.setAttribute("allCats", list);
		// 转发到真实的首页
		return "/jsp/index.jsp";
	}
      

}
