class Programmer extends Employee {
    Programmer() {
    }

    void processSalary() {
        da = 0.97 * bp;
        hra = 0.10 * bp;
        pf = 0.12 * bp;
        staffClub = 0.001 * bp;
        gross = bp + da + hra;
        net = gross - (pf + staffClub);
    }
}

class AssistantProfessor extends Employee {
    AssistantProfessor() {
    }

    void processSalary() {
        da = 0.97 * bp;
        hra = 0.10 * bp;
        pf = 0.12 * bp;
        staffClub = 0.001 * bp;
        gross = bp + da + hra;
        net = gross - (pf + staffClub);
    }
}

class AssociateProfessor extends Employee {
    AssociateProfessor() {
    }

    void processSalary() {
        da = 0.97 * bp;
        hra = 0.10 * bp;
        pf = 0.12 * bp;
        staffClub = 0.001 * bp;
        gross = bp + da + hra;
        net = gross - (pf + staffClub);
    }

}

class Professor extends Employee {
    Professor() {
    }

    void processSalary() {
        da = 0.97 * bp;
        hra = 0.10 * bp;
        pf = 0.12 * bp;
        staffClub = 0.001 * bp;
        gross = bp + da + hra;
        net = gross - (pf + staffClub);
    }
}