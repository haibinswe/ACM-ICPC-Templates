String s = new String("The=Java=platform=is=the=ideal=platform=for=network=computing");
StringTokenizer st = new StringTokenizer(s, "=", true); //当为false时不包括=
System.out.println("Token Total: " + st.countTokens());
while (st.hasMoreElements())
{
    System.out.println(st.nextToken());
}
