.PHONY: clean All

All:
	@echo "----------Building project:[ Cipher - Debug ]----------"
	@cd "Cipher" && "$(MAKE)" -f  "Cipher.mk"
clean:
	@echo "----------Cleaning project:[ Cipher - Debug ]----------"
	@cd "Cipher" && "$(MAKE)" -f  "Cipher.mk" clean
