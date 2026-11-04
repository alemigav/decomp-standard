/* FUN_80087af0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80087af0  body 0x80087af0..0x80087c5f  size 368 B
 * body sha256 d2b7dd295c87cd07fbd9a81dea30a435fd2026bb76292936ed47cb5fba8c832d
 * provider record sha256 95f05619975ab8491f21fa96c8ff43adc381c5c2b3b557baaad573adfa2610f8
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80087af0(int param_1)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  uint uVar4;
  
  piVar3 = *(int **)(param_1 + 4);
  iVar1 = *piVar3;
  if ((&DAT_8012a034)[iVar1] == '\x03') {
    if ((piVar3[4] & 1U) == 0) {
      uVar2 = piVar3[2];
      uVar4 = 0;
      if (0x96 < uVar2) {
        func_0x80008110(&UNK_80129e94 + iVar1 * 0x68);
        uVar4 = uVar2;
      }
    }
    else {
      uVar2 = piVar3[3];
      if ((0x96 < uVar2) || (uVar4 = 0, piVar3[4] == 1)) {
        func_0x80007f50(&UNK_80129e94 + iVar1 * 0x68);
        uVar4 = uVar2;
      }
    }
    iVar1 = piVar3[4];
    piVar3[4] = iVar1 + -1;
    if (iVar1 + -1 == 0) {
      (&DAT_8012a034)[*piVar3] = 2;
      if (piVar3[5] != 0) {
        osSendMesg(piVar3[5],0);
      }
    }
    else if (uVar4 == 0) {
      FUN_80087af0(param_1);
    }
    else {
      func_0x8000cec0(0x8013a320);
    }
  }
  return;
}
