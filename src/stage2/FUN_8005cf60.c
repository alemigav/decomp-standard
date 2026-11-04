/* FUN_8005cf60
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005cf60  body 0x8005cf60..0x8005d2cb  size 876 B
 * body sha256 ff9c9ca4dadc3de51bbcc1baea5ca48062875cf4d101438822b01a8f102026d5
 * provider record sha256 e46772cb966716427b09794ae727548cf5b22d66316d3d9fff3a5e6fe70e668a
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8005cf60(int param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  char cVar2;
  short local_28 [8];
  
  local_28[0] = 0;
  local_28[1] = 0xf;
  local_28[2] = 0xb;
  local_28[3] = 0;
  local_28[4] = 0xd;
  if (*(char *)(param_1 + 7) == '\0') {
    *(undefined1 *)(param_1 + 7) = 1;
    *(int *)(param_1 + 0x1e8) = local_28[*(ushort *)(param_1 + 0x1f0) >> 0xd] * 0x1000000 + 0x700;
    DAT_800e112a = DAT_800e112a | 0x18;
    if ((*(ushort *)(param_1 + 0x1aa) & 0xfff) == 1) {
      DAT_800e112a = DAT_800e112a & 0xffef;
    }
  }
  if ((param_4 & 0x100) == 0) {
    *(undefined2 *)(param_1 + 6) = 0x300;
    return;
  }
  if ((*(ushort *)(param_1 + 0x1aa) & 0xfff) == 0x11) {
    DAT_800e110c = DAT_800e110c | 0x40000;
  }
  else {
    if ((((param_4 & 0x10) != 0) || ('\x19' < DAT_800df8c1)) &&
       ((*(ushort *)(param_1 + 0x1f0) & 0x8000) == 0)) {
      *(undefined1 *)(param_1 + 7) = 0;
      *(ushort *)(param_1 + 0x1f0) = *(ushort *)(param_1 + 0x1f0) & 0x1fff | 0x8000;
      return;
    }
    if ((((param_4 & 0x20) != 0) || (DAT_800df8c1 < -0x19)) &&
       ((*(ushort *)(param_1 + 0x1f0) & 0x2000) == 0)) {
      *(undefined1 *)(param_1 + 7) = 0;
      *(ushort *)(param_1 + 0x1f0) = *(ushort *)(param_1 + 0x1f0) & 0x1fff | 0x2000;
      return;
    }
    if ((((param_4 & 0x30) == 0) && (DAT_800df8c1 < '\x1a')) &&
       ((-0x1a < DAT_800df8c1 && ((*(ushort *)(param_1 + 0x1f0) & 0x4000) == 0)))) {
      *(undefined1 *)(param_1 + 7) = 0;
      *(ushort *)(param_1 + 0x1f0) = *(ushort *)(param_1 + 0x1f0) & 0x1fff | 0x4000;
      return;
    }
  }
  if (((DAT_800e8b58 & 1) == 0) && ((DAT_800df90e & 4) != 0)) {
    *(undefined2 *)(param_1 + 6) = 0x500;
  }
  if ((param_4 & 0x40) != 0) {
    iVar1 = FUN_8008cce4(*(ushort *)(param_1 + 0x1aa) & 0xfff);
    if (iVar1 != 0) {
      *(undefined2 *)(param_1 + 6) = 0x200;
      return;
    }
    if ((DAT_800df918 & 0x40) != 0) {
      cVar2 = FUN_8008d00c();
      if ((cVar2 == '\0') || ((*(ushort *)(param_1 + 0x1aa) & 0xfff) - 9 < 3)) {
        FUN_80077adc(0x1010001,param_1 + 0x28);
      }
      else {
        *(undefined2 *)(param_1 + 6) = 0x400;
      }
    }
  }
  cVar2 = DAT_800df8c0;
  if (((param_4 & 8) != 0) || (DAT_800df8c0 < -0x19)) {
    *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + -0x40;
  }
  if (((param_4 & 2) != 0) || ('\x19' < cVar2)) {
    *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + 0x40;
  }
  FUN_80089d54(param_1,param_2,param_3,0x200);
  return;
}
