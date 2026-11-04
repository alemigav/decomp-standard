/* FUN_8008b048
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008b048  body 0x8008b048..0x8008b09b  size 84 B
 * body sha256 8b785305bd85f7eb276ab239cdbef84f499b2b1c96df96f985eee5934f02e57a
 * provider record sha256 7a9272861b800368f5c785a5b9428fd58208fa11738ab3387c6911fe9b0fa54b
 * callees 2 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8008b048(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = func_0x8000cd40(1);
  if (param_1 == 0) {
    param_1 = 1;
  }
  uVar2 = FUN_8008af80(param_1);
  func_0x8000cd40(uVar1);
  return uVar2;
}
