/* FUN_8000de40
 * image   boot (boot), base 0x80000480
 * address 0x8000de40  body 0x8000de40..0x8000de77  size 56 B
 * body sha256 94d3119cacfafee6eab613e2b6e99804e225165961794deb47827e6fb85e08a1
 * provider record sha256 29366beae48e967b651496375f6700b70ba9771ffba5145f2f050a87e3475950
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
char * FUN_8000de40(char *param_1,char param_2)

{
  char cVar1;
  
  cVar1 = *param_1;
  while( true ) {
    if (cVar1 == param_2) {
      return param_1;
    }
    param_1 = param_1 + 1;
    if (cVar1 == '\0') break;
    cVar1 = *param_1;
  }
  return (char *)0x0;
}
