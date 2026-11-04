/* FUN_80168720
 * image   ovl_00a1414 (ovl), base 0x80161cf0
 * address 0x80168720  body 0x80168720..0x801687ef  size 208 B
 * body sha256 8ca559d141e56716779c23bf204d41ed5658f94023f6d81824c3517cd7d9d8c1
 * provider record sha256 beabf7893bf7103943f6500a107b4135702ff00f09fc98f35c78b4a948a14d0f
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80168720(int param_1,undefined4 param_2,int param_3)

{
  char cVar1;
  char cVar2;
  char *pcVar3;
  
  pcVar3 = (char *)((uint)*(byte *)(param_1 + 0x2c1) * 2 + param_3);
  cVar1 = *pcVar3;
  if (cVar1 != -1) {
    cVar2 = pcVar3[1];
    if (cVar2 == -1) {
      *(undefined1 *)(param_1 + 0x2c0) = 0;
      *(undefined1 *)(param_1 + 0x2c1) = 0;
    }
    else if (*(char *)(param_1 + 0x2c0) == '\0') {
      *(char *)(param_1 + 0x2c0) = cVar2;
      *(char *)(param_1 + 0x2c2) = cVar1;
      *(char *)(param_1 + 0x2c1) = *(char *)(param_1 + 0x2c1) + '\x01';
    }
    else {
      *(char *)(param_1 + 0x2c0) = *(char *)(param_1 + 0x2c0) + -1;
    }
  }
  return;
}
