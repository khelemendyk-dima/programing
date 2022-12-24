package com.epam.rd.contactbook;

public class Contact {
    private String contactName;
    private final ContactInfo[] contactInfos = new ContactInfo[10];
    private int emailsCounter = 2;
    private int socialCounter = 5;
    public Contact(String contactName) {
        if (contactName == null) {
            throw new IllegalArgumentException();
        }
        this.contactName = contactName;
        this.contactInfos[0] = new NameContactInfo();
    }

    private class NameContactInfo implements ContactInfo {
        @Override
        public String getTitle() {
            return "Name";
        }

        @Override
        public String getValue() {
            return contactName;
        }
    }

    public static class Email implements ContactInfo {
        private final String email;
        Email(String email) {
            this.email = email;
        }
        @Override
        public String getTitle() {
            return "Email";
        }

        @Override
        public String getValue() {
            return email;
        }
    }

    public static class Social implements ContactInfo {
        private final String title;
        private final String id;
        Social(String title, String id) {
            this.title = title;
            this.id = id;
        }
        @Override
        public String getTitle() {
            return title;
        }

        @Override
        public String getValue() {
            return id;
        }
    }

    private boolean isNull(String a, String b) {
        return a == null
                || b == null;
    }

    public void rename(String newName) {
        if (newName == null
                || "".equals(newName)) {
            return;
        }
        this.contactInfos[0] = new NameContactInfo();
        this.contactName = newName;
    }

    public Email addEmail(String localPart, String domain) {
        if (isNull(localPart, domain) || emailsCounter == 5) {
            return null;
        }
        Email email = new Email(localPart + '@' + domain);
        this.contactInfos[emailsCounter] = email;
        emailsCounter++;
        return email;
    }

    public Email addEpamEmail(String firstname, String lastname) {
        if (isNull(firstname, lastname) || emailsCounter == 5) {
            return null;
        }
        String epamEmail = firstname + '_' + lastname + "@epam.com";
        Email email = new Email(epamEmail) {
            @Override
            public String getTitle() {
                return "Epam Email";
            }

            @Override
            public String getValue() {
                return epamEmail;
            }
        };
        this.contactInfos[emailsCounter] = email;
        emailsCounter++;
        return email;
    }

    public ContactInfo addPhoneNumber(int code, String number) {
        if (code <= 0 || number == null || this.contactInfos[1] != null) {
            return null;
        }
        ContactInfo phone = new ContactInfo() {
            final String phone = '+' + String.valueOf(code) + ' ' + number;
            @Override
            public String getTitle() {
                return "Tel";
            }

            @Override
            public String getValue() {
                return phone;
            }
        };
        this.contactInfos[1] = phone;
        return phone;
    }

    public Social addTwitter(String twitterId) {
        if (twitterId == null || socialCounter == 10) {
            return null;
        }
        Social twitter = new Social("Twitter", twitterId);
        this.contactInfos[socialCounter] = twitter;
        socialCounter++;
        return twitter;
    }

    public Social addInstagram(String instagramId) {
        if (instagramId == null || socialCounter == 10) {
            return null;
        }
        Social instagram = new Social("Instagram", instagramId);
        this.contactInfos[socialCounter] = instagram;
        socialCounter++;
        return instagram;
    }

    public Social addSocialMedia(String title, String id) {
        if (isNull(title, id) || socialCounter == 10) {
            return null;
        }
        Social socialMedia = new Social(title, id);
        this.contactInfos[socialCounter] = socialMedia;
        socialCounter++;
        return socialMedia;
    }

    public ContactInfo[] getInfo() {
        int nullCounter = 0;
        for (ContactInfo el : contactInfos) {
            if (el == null) {
                nullCounter++;
            }
        }
        ContactInfo[] newContactInfos = new ContactInfo[10 - nullCounter];
        for (int i = 0, j = 0; i < contactInfos.length; i++) {
            if (contactInfos[i] != null) {
                newContactInfos[j] = contactInfos[i];
                j++;
            }
        }
        return newContactInfos;
    }

}
