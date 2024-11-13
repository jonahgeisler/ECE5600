BUILD_DIR := build
ARTIFACT_DIR := artifacts
NAME ?= test
NUMBER ?= 0
FOLDER_NAME := $(shell basename `pwd`)

build: build_dir
	cmake --build ${BUILD_DIR}
	@echo ""
	@echo "Binaries are found in ${BUILD_DIR}"

.PHONY: artifact_dir
artifact_dir:
	mkdir -p artifacts

.PHONY: stack_artifact
stack_artifact: artifact_dir build
	ln -f $(BUILD_DIR)/stack $(ARTIFACT_DIR)/stack

.PHONY: build_dir
build_dir:
	mkdir -p $(BUILD_DIR);
	cd $(BUILD_DIR); cmake ..

.PHONY: clean
clean:
	rm -rf ${BUILD_DIR}

.PHONY: submision
submission: stack_artifact
# Add anything here that you want repeated for each submission
	@echo "Copying file(s) to artifact directory"
# Insert here any artifacts you want copied when running this target
#
# Tar everything together
	cd ..; \
		tar --exclude='./.git' --exclude='./build' --exclude='.gitignore' \
		-cvzf ${NAME}_lab${NUMBER}.tar.gz ${FOLDER_NAME}
