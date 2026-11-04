/* FUN_8007d748
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007d748  body 0x8007d748..0x8007d813  size 204 B
 * body sha256 a739e1da170a97b91daa0099253333d9b408a9e3520b21b07ef1400570efc446
 * provider record sha256 465a6038d93d7084af358d806cdefa02cf1a31c7a742f6279303763dde3bc234
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007d748(int param_1)

{
  short sVar2;
  int iVar1;
  
  if (*(char *)(param_1 + 6) == '\0') {
    sVar2 = FUN_80032e74(&DAT_800e1130,*(undefined4 *)(param_1 + 0x28),
                         *(undefined4 *)(param_1 + 0x30),1);
    *(short *)(param_1 + 0x1f6) = sVar2 * 0x60;
    if ((short)(sVar2 * 0x60) == 0) {
      *(undefined2 *)(param_1 + 0x1f6) = 0x60;
    }
    *(undefined1 *)(param_1 + 0x206) = 0;
  }
  iVar1 = FUN_80032f64(param_1,(int)DAT_800e1196,0x200);
  if ((iVar1 == 0) && ('\x05' < *(char *)(param_1 + 0x206))) {
    *(undefined4 *)(param_1 + 4) = 0x1000000;
  }
  if ('x' < *(char *)(param_1 + 0x206)) {
    *(undefined4 *)(param_1 + 4) = 0x1000000;
  }
  *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + *(short *)(param_1 + 0x1f6);
  return;
}
