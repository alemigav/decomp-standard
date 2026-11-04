/* FUN_8000aa10
 * image   boot (boot), base 0x80000480
 * address 0x8000aa10  body 0x8000aa10..0x8000aaef  size 224 B
 * body sha256 023604fae35db75779ed12a0bd401423aa6a31d4e57a32f75c1082e550bec060
 * provider record sha256 8fece0291147b70844da73422998706930e8a80f8e7425592d5ae756786bafc9
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8000aa10(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined1 auStack_28 [2];
  ushort local_26;
  undefined1 auStack_20 [8];
  
  FUN_8000aaf0(param_2);
  FUN_8000d1f0(1,&DAT_80016470);
  osRecvMesg(param_1,auStack_20,1);
  uVar1 = FUN_8000d1f0(0,&DAT_80016470);
  osRecvMesg(param_1,auStack_20,1);
  FUN_8000ab80(param_2,auStack_28);
  if (((local_26 & 0x100) == 0) || (uVar2 = 2, (local_26 & 0x200) == 0)) {
    if ((local_26 & 0x1ff) == 0x100) {
      uVar2 = 4;
      if ((local_26 & 0x400) == 0) {
        uVar2 = uVar1;
      }
    }
    else {
      uVar2 = 1;
    }
  }
  return uVar2;
}
