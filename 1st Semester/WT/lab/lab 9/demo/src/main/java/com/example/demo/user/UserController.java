package com.example.demo.user;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;

@Controller
public class UserController {
    @Autowired
    private UserService service;

    @GetMapping("/")
    public String home(Model model) {
        List<User> userList = service.listAll();
        model.addAttribute("userList", userList);
        System.out.println("GET /");
        return "index";
    }

    @GetMapping("/create")
    public String new_user(Model model) {
        return "new";
    }

    @PostMapping("/new")
    public String create(@ModelAttribute User u) {
        service.save(u);
        return "redirect:/";
    }

    @GetMapping("/delete/{id}")
    public String delete(@PathVariable(name = "id") int id) {
        service.delete(id);
        return "redirect:/";
    }
}
