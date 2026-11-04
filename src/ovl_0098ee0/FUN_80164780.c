/* FUN_80164780
 * image   ovl_0098ee0 (ovl), base 0x80161cf0
 * address 0x80164780  body 0x80164780..0x80164887  size 264 B
 * body sha256 77f5ba8394be017420502aae7f34c99f0b95960b8bf255c5f0167df9252d2186
 * provider record sha256 fead90ccc4a8f880ac412d6ef3e34a27c6461b1ed779753cb29e9cf2cc6376a0
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80164780(uint *param_1)

{
  char cVar1;
  
  switch(*(undefined1 *)((int)param_1 + 6)) {
  case 0:
    *(undefined2 *)(param_1 + 0x9c) = 0;
    *(byte *)(param_1 + 0x97) = *(byte *)(param_1 + 0x97) | 4;
    *param_1 = *param_1 | 8;
    *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + '\x01';
  case 1:
    if ((param_1[0x9c] & 0x10000) != 0) {
      *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + '\x01';
switchD_801647b0_caseD_2:
      func_0x80036c68(param_1,1,0,0);
      if ((param_1[0x9c] & 0x20000) != 0) {
        cVar1 = *(char *)((int)param_1 + 6);
        param_1[0x7a] = 0x1f00;
LAB_80164858:
        *(char *)((int)param_1 + 6) = cVar1 + '\x01';
      }
    }
    break;
  case 2:
    goto switchD_801647b0_caseD_2;
  case 3:
    *(undefined1 *)(param_1 + 0x7a) = 0;
    func_0x80089d54(param_1,param_1[0x8b],param_1[0x8c],0x80);
    if ((param_1[0x9c] & 0x40000) == 0) {
      return;
    }
    cVar1 = *(char *)((int)param_1 + 6);
    goto LAB_80164858;
  case 4:
    func_0x80036c68(param_1,1,0x1f,0);
  }
  return;
}
