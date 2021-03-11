public class FinalKeyword {
    final class Secret {

    }

    class ItGivesAnError extends Secret {
        // Nemitunim az final class ers bari konim
    }

    final String password = "123";

    public void changePassword(String newPassword) {
        password = newPassword;
        // Nemitunim reasign konim !
    }

}
