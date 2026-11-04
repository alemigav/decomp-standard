/* FUN_80074e84
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80074e84  body 0x80074e84..0x80074f63  size 224 B
 * body sha256 789aa30accbb11d909eb300eb624e2f17087b3e932119984c5c1bb76dd16f320
 * provider record sha256 fc577831276a1f2bb358cdddaf6f25aef9fa36292dd672b6d683b7d8126df7c5
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined1 FUN_80074e84(undefined4 param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  undefined1 *puVar2;
  short *psVar3;
  int iVar4;
  undefined4 local_28 [2];
  undefined4 local_20;
  
  iVar4 = (int)**(short **)(DAT_800df92c + 0x34);
  psVar3 = *(short **)(DAT_800df92c + 0x34) + iVar4 * 6 + 1;
  iVar4 = iVar4 + -1;
  if (iVar4 != -1) {
    puVar2 = (undefined1 *)((int)psVar3 + -3);
    local_28[0] = param_1;
    local_20 = param_2;
    do {
      psVar3 = psVar3 + -6;
      if (((((int)*(short *)(puVar2 + 1) & 0x80U) == 0) &&
          (param_3 == ((int)*(short *)(puVar2 + 1) & 0x7fU))) &&
         (iVar1 = FUN_80083e14(local_28,psVar3), iVar1 != 0)) {
        return *puVar2;
      }
      iVar4 = iVar4 + -1;
      puVar2 = puVar2 + -0xc;
    } while (iVar4 != -1);
  }
  return 0x1d;
}
