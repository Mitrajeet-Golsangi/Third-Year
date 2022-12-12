package com.example.demo.user;

import jakarta.persistence.Entity;
import jakarta.persistence.GeneratedValue;
import jakarta.persistence.GenerationType;
import jakarta.persistence.Id;
import jakarta.persistence.Table;

@Entity
@Table(name = "user")
public class User {
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private int id;

    private String name;
    private String email;
    private String contact;
    private String password;

    // Constructors
    public User() {
        super();
    }

    public User(int id, String name, String email, String contact, String password) {
        super();
        this.id = id;
        this.name = name;
        this.email = email;
        this.contact = contact;
        this.password = password;
    }

    // To String method
    @Override
    public String toString() {
        return "User [id=" + id + ", name=" + name + ", email=" + email + ", contact=" + contact + ", password="
                + password + "]";
    }

    // Getter Setters
    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public String getContact() {
        return contact;
    }

    public void setContact(String contact) {
        this.contact = contact;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

}
