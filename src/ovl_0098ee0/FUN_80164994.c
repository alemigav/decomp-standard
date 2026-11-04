/* FUN_80164994
 * image   ovl_0098ee0 (ovl), base 0x80161cf0
 * address 0x80164994  body 0x80164994..0x80164ac7  size 308 B
 * body sha256 e9606794a4584fdd408491f71bb769a568da1063e41b94b482de28bd2baf6ffa
 * provider record sha256 f5a670b191d76d2abe1aaeec82864c0cc58def63e866f84b9a2d6bb6a0adb23b
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80164994(int param_1)

{
  char cVar1;
  
  switch(*(undefined1 *)(param_1 + 6)) {
  case 0:
    *(undefined2 *)(param_1 + 0x270) = 0;
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + '\x01';
  case 1:
    if ((*(ushort *)(param_1 + 0x270) & 8) == 0) {
      if (*(ushort *)(param_1 + 0x270) != 0) {
        *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + '\x01';
switchD_801649c4_caseD_2:
        func_0x80036c68(param_1,1,0xf,0);
        if ((*(ushort *)(param_1 + 0x270) & 2) != 0) {
          *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + '\x01';
switchD_801649c4_caseD_3:
          func_0x80036b84(param_1,0xc,0x1f,0);
          *(undefined1 *)(param_1 + 0x1e9) = 1;
          if ((*(ushort *)(param_1 + 0x270) & 4) != 0) {
            *(undefined1 *)(param_1 + 0x1e9) = 0;
            *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + '\x01';
switchD_801649c4_caseD_4:
            cVar1 = func_0x80036c68(param_1,0xc,0xf,0);
            *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + cVar1;
          }
        }
      }
    }
    else {
      *(undefined1 *)(param_1 + 6) = 5;
    }
    break;
  case 2:
    goto switchD_801649c4_caseD_2;
  case 3:
    goto switchD_801649c4_caseD_3;
  case 4:
    goto switchD_801649c4_caseD_4;
  case 5:
    if ((*(ushort *)(param_1 + 0x270) & 8) != 0) {
      *(undefined4 *)(param_1 + 4) = 0x1010000;
      *(ushort *)(param_1 + 0x1aa) = *(ushort *)(param_1 + 0x1aa) & 0xbfff;
    }
  }
  return;
}
